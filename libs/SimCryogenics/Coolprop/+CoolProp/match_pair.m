function varargout = match_pair(varargin)
  [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(100,varargin{:});
end
